#include "counter.hpp"

Counter::Counter(int startValue, QObject* parent)
    : QObject(parent), m_count(startValue) 
{
}

int Counter::Increment() 
{
    m_count++;
    emit countChanged(m_count);
    return m_count;
}

int Counter::Decrement() 
{
    m_count--;
    emit countChanged(m_count);
    return m_count;
}

void Counter::setCount(int value) 
{
    if (m_count != value) {
        m_count = value;
        emit countChanged(m_count);
    }
}
