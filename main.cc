#include <emscripten/bind.h>
using namespace emscripten;
typedef void(*Fn)();
class Test {
public:
  Fn fn = nullptr;
  void setCb(val _cb){
    // val ptr = val::module_property("addFunction")(_cb,std::string("v")); works
    val ptr = val::global("addFunction")(_cb,std::string("v"));// not  works
    int ptr_int = ptr.as<int>();
    fn = reinterpret_cast<Fn>(ptr_int);
  }
  void callCb(){
    fn();
  }
};
EMSCRIPTEN_BINDINGS(test){
  class_<Test>("Test")
  .constructor<>()
  .function("setCb",&Test::setCb)
  .function("callCb",&Test::callCb);
}