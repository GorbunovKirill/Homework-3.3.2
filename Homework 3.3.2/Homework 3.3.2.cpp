#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class table {
private:
    std::vector<std::vector<T>> data;
    int rows;
    int cols;

public:
    // Конструктор
    table(int rows, int cols) : rows(rows), cols(cols) {
        if (rows <= 0 || cols <= 0) {
            throw std::invalid_argument("Должно быть больше нуля");
        }
        data.resize(rows, std::vector<T>(cols));
    }

    std::vector<T>& operator[](int index) {
        if (index < 0 || index >= rows) {
            throw std::out_of_range("Вне диапозона");
        }
        return data[index];
    }

    const std::vector<T>& operator[](int index) const {
        if (index < 0 || index >= rows) {
            throw std::out_of_range("Вне диапозона");
        }
        return data[index];
    }

    std::pair<int, int> Size() const {
        return { rows, cols };
    }
};

int main() {

    setlocale(LC_ALL, "Russian");

    try {


        table<int> test(2, 3);
        test[0][0] = 4;
        std::cout << test[0][0] << std::endl;

        auto size = test.Size();
        std::cout << "Рядов: " << size.first << ", Колонок: " << size.second << std::endl;

     
    }
    catch (const std::exception& ex) {
        std::cout << "Исключение: " << ex.what() << std::endl;
    }

    return 0;
}
