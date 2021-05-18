const factor = require('./main');
async function main(){
  const m = await factor();
  console.log('m:',m.Test)
  const test = new m.Test();
  test.setCb(() => {
    console.log('hello world');
  })
  test.callCb();
  
}
main()