#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    cout << "Content-type: text/html\n\n";
    cout << "<html><head><title>Order Confirmation</title></head><body>";

    string name, address, item;

    char *data = getenv("QUERY_STRING");
    if (data) {
        string query = data;
        // Dummy parse example (real parsing required)
        name = "User";
        address = "123 Street";
        item = "Pizza";

        ofstream out("../orders.txt", ios::app);
        out << "Name: " << name << ", Address: " << address << ", Item: " << item << "\n";
        out.close();

        cout << "<h2>Thank you for your order!</h2>";
    } else {
        cout << "<h2>Error receiving order</h2>";
    }

    cout << "</body></html>";
    return 0;
}