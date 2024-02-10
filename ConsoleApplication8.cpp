

#include <iostream>
#include <string>

bool isMantissa(std::string s, int& i);
bool isOrder(std::string s, int& i);
bool real_number(std::string s, int size, int& i);

bool real_number(std::string s, int size, int& i) {
    if (i == size) {
        return true;
    }
    if (s[i] == 'e') {
        if (i < size - 1) {
            i++;
            if (isOrder(s, i)) {  // После обработки экспоненциальной части, вызываю real_number для обработки оставшейся части
                return real_number(s, size, i);
            }
        }
    }
    else {
        return isMantissa(s, i);  // Обработка мантиссы
    }
    return false;
}

bool isSign(char s) {
    return (s == '-' || s == '+');
}

bool isDigit(char s) {
    return (s >= '0' && s <= '9');
}

bool flag_point = false;

bool isMantissa(std::string s, int& i) {
    if (s[i] == '.' && !flag_point) {
        flag_point = true;
        return true;
    }
    else {
        if (isDigit(s[i])) {
            return true;
        }
    }
    return false;
}

bool flag_e = false;
bool flag_sign = false;

bool isOrder(std::string s, int& i) {
    if (s[i] == 'e' && !flag_e) {
        flag_e = true;
        return true;
    }
    if (!flag_sign && (s[i] == '-' || s[i] == '+')) {
        flag_sign = true;
        return true;
    }
    if (isDigit(s[i])) {
        return true;
    }
    return false;
}

int main() {
    std::string s;
    std::cin >> s;
    int i = 0;
    if (real_number(s, s.length(), i)) {
        std::cout << "true";
    }
    else {
        std::cout << "false";
    }
    return 0;
}