#include <iostream>
#include <vector>
#include <string>


class Expense{
    private:
        std::string date;
        std::string description;
        double amount;
        std::string category = "";
    public:
        Expense(const std::string& date, const std::string& description, const double amount): 
        date(date), description(description), amount(amount){};

        std::string get_date(){
            return (const std::string&)date;
        };

        std::string get_description(){
            return (const std::string&)description;
        };

        double get_amount(){
            return (const double)amount;
        };

};



int main(){
    std::vector<Expense> v1;
    v1.push_back(Expense("8.10.2026", "Biedronka", 26.48)); 
    v1.push_back(Expense("6.10.2026", "Zabka", 18.05));
    v1.push_back(Expense("1.10.2026", "Lidl", 150.43));
    for(auto& expense : v1){
        std::cout << "date: " << expense.get_date() << "\n";
        std::cout << "description: " <<expense.get_description() << "\n";
        std::cout << "amount: " << expense.get_amount() << "\n";
    }
}