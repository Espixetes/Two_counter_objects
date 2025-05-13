#include <QCoreApplication>
#include <QDebug>
#include "counter.hpp"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);


    Counter counter1(5);
    Counter counter2(10);


    QObject::connect(&counter1, &Counter::countChanged, &counter2, &Counter::setCount);
    QObject::connect(&counter2, &Counter::countChanged, &counter1, &Counter::setCount);


    qDebug() << "After incrementing counter1:";
    counter1.Increment();
    qDebug() << "Counter1:" << counter1.Increment() - 1; // Adjust for display after increment
    qDebug() << "Counter2:" << counter2.Increment() - 1;


    qDebug() << "\nAfter incrementing counter2:";
    counter2.Increment();
    qDebug() << "Counter1:" << counter1.Increment() - 1;
    qDebug() << "Counter2:" << counter2.Increment() - 1;


    qDebug() << "\nAfter decrementing counter1:";
    counter1.Decrement();
    qDebug() << "Counter1:" << counter1.Increment() - 1;
    qDebug() << "Counter2:" << counter2.Increment() - 1;


    qDebug() << "\nAfter decrementing counter2:";
    counter2.Decrement();
    qDebug() << "Counter1:" << counter1.Increment() - 1;
    qDebug() << "Counter2:" << counter2.Increment() - 1;

    return app.exec();
}
