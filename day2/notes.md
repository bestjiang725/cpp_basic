# 第二日指针剩余

## 1.unique_ptr
 - unique_ptr 与昨天的shared_ptr不同，shared_ptr允许多个指针指向同一个对象，unique_ptr则“独占”所指向的对象。
- unique_ptr 虽然不能被拷贝和赋值，但可以用release() 获取指针，然后手动delete，或者reset重置。
- unique_ptr 释放对象时，会调用析构函数，但shared_ptr不会。
- 还有一种删除器，unique_ptr<T, D>，可以自主决定用什么方式删除。更为灵活

## 2.weak_ptr
- weak_ptr 允许一个对象被多个指针所引用，但weak_ptr不参与计数，也不会触发对象的析构。
- weak_ptr 人如其名，弱引用。weak_ptr 可以转换成shared_ptr，但shared_ptr 不能转换成weak_ptr。
