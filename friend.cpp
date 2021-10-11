//友元函数与友元类
/*
(1) 友元关系不能被继承。
(2) 友元关系是单向的，不具有交换性。若类B是类A的友元，类A不一定是类B的友元，要看在类中是否有相应的声明。
(3) 友元关系不具有传递性。若类B是类A的友元，类C是B的友元，类C不一定是类A的友元，同样要看类中是否有相应的申明
*/
#include <iostream>
class A;

class B {
public:
    int func2(A& a);
};

class A {
    friend int func1(A& a);
    friend int B::func2(A& a);
    friend class C;
private:
    int a=0;
};

class C {
public:
    void setA(int aa) {
        a.a = aa;
    }
    void print() {
        std::cout << "data3 =" << a.a<<std::endl;
    }
private:
    A a;
};

int func1(A& a) {
    a.a = 10;
    return a.a;
}

int B::func2(A& a) {
	a.a = 20;
	return a.a;
}

int main()
{
    A a;
    auto data1 = func1(a);
    std::cout << "data1 =" << data1 << std::endl;

	B b;
	auto data2 = b.func2(a);
	std::cout << "data2 =" << data2 << std::endl;

    C c;
    c.setA(30);
    c.print();
}

