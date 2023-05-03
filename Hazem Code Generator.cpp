
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

std::string generate_code() {
    std::string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    std::string code = "WISH$";
    for (int i = 0; i < 8; i++) {
        int index = rand() % chars.length();
        code += chars[index];
    }
    return code;
}

int main() {
    srand(time(0));
    std::ofstream file("codes.txt");
    int num_codes;
    std::cout << "Enter the number of codes to generate: ";
    std::cin >> num_codes;
    int i = 0;
    while (i < num_codes) {
        file << generate_code() << std::endl << std::endl;
        i++;
    }
    file.close();
    std::cout << num_codes << " codes written to file 'codes.txt'" << std::endl;
    return 0;
}
