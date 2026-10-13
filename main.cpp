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

        const std::string& get_date() const{
            return date;
        }

        const std::string& get_description() const{
            return description;
        }

        const double get_amount() const{
            return amount;
        }

        void set_category(const std::string& new_category){
            category = new_category;
        }

        const std::string& get_category() const{
            return category;
        }

};


class CategorizationRule{
    public:
        virtual bool apply(Expense& expense) = 0;
        virtual ~CategorizationRule() = default;
};

class KeywordRule : public CategorizationRule{
    private:
        std::string keyword;
        std::string target_category;
    public:
        KeywordRule(const std::string& kw, const std::string& tc): 
        keyword(kw), target_category(tc){}
        bool apply(Expense& expense) override{
            if(expense.get_description().find(keyword) != std::string::npos){
                expense.set_category(target_category);
                return true;
            }else{
                return false;
            }
        }
};



int main(){
    std::vector<Expense> v1;
    v1.push_back(Expense("8.10.2026", "Biedronka", 26.48)); 
    v1.push_back(Expense("6.10.2026", "Zabka", 18.05));
    v1.push_back(Expense("1.10.2026", "Lidl", 150.43));
    
    KeywordRule food("Biedronka", "Spozywcze");

    std::vector<CategorizationRule*> rules;

    rules.push_back(&food);

    for(auto& expense : v1){
        for(auto rule : rules){
            if(rule->apply(expense)) break;
        }
        std::cout << expense.get_category() << std::endl;
    }
}