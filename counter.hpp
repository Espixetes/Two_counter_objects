#include <QObject>

class Counter : public QObject {
    Q_OBJECT
public:
    Counter(int startValue, QObject* parent = nullptr);
    int Increment();
    int Decrement();

signals:
    void countChanged(int newValue);

public slots:
    void setCount(int value);

private:
    int m_count;
};
