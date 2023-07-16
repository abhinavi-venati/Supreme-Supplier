#include <iostream>
#include <vector>
#include <map>
#include <limits>
#include <stdexcept>

using namespace std;

class Supplier {
protected:
    string name;
    int deliveryTime;
    double orderAccuracy;
    double productQuality;
    int leadTime;
    double pricing;

public:
    Supplier(string name, int deliveryTime, double orderAccuracy, double productQuality, int leadTime, double pricing)
        : name(name), deliveryTime(deliveryTime), orderAccuracy(orderAccuracy), productQuality(productQuality), leadTime(leadTime), pricing(pricing) {}

    virtual double calculateScore(double deliveryWeight, double accuracyWeight, double qualityWeight, double leadTimeWeight, double pricingWeight) const {
        return (deliveryTime * deliveryWeight) + (orderAccuracy * accuracyWeight) +
               (productQuality * qualityWeight) + (leadTime * leadTimeWeight) + (pricing * pricingWeight);
    }

    virtual void displayDetails() const {
        cout << "Name: " << name << endl;
        cout << "Delivery Time: " << deliveryTime << " days" << endl;
        cout << "Order Accuracy: " << orderAccuracy << endl;
        cout << "Product Quality: " << productQuality << endl;
        cout << "Lead Time: " << leadTime << " days" << endl;
        cout << "Pricing: " << pricing << endl;
    }

    string getName() const {
        return name;
    }
};

class PreferredSupplier : public Supplier {
private:
    int specialDiscount;

public:
    PreferredSupplier(string name, int deliveryTime, double orderAccuracy, double productQuality, int leadTime, double pricing, int specialDiscount)
        : Supplier(name, deliveryTime, orderAccuracy, productQuality, leadTime, pricing), specialDiscount(specialDiscount) {}

    double calculateScore(double deliveryWeight, double accuracyWeight, double qualityWeight, double leadTimeWeight, double pricingWeight) const override {
        double score = Supplier::calculateScore(deliveryWeight, accuracyWeight, qualityWeight, leadTimeWeight, pricingWeight);
        return score * (1 + (specialDiscount / 100.0));
    }

    void displayDetails() const override {
        cout << "Preferred Supplier" << endl;
        Supplier::displayDetails();
    }
};

vector<Supplier*> getSupplierData() {
    vector<Supplier*> suppliers;

    while (true) {
        int numSuppliers;
        cout << "Enter the number of suppliers: ";
        cin >> numSuppliers;

        if (cin.fail() || numSuppliers <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid number of suppliers. Please enter a positive integer." << endl;
            continue;
        }

        cin.ignore(); 

        for (int i = 0; i < numSuppliers; i++) {
            string name;
            int deliveryTime;
            double orderAccuracy;
            double productQuality;
            int leadTime;
            double pricing;
            int specialDiscount;

            cout << "Supplier " << i + 1 << ":" << endl;

            while (true) {
                cout << "Name: ";
                getline(cin, name);

                if (name.empty()) {
                    cout << "Invalid input. Please enter a non-empty name." << endl;
                    continue;
                }

                break;
            }

            while (true) {
                cout << "Delivery Time (in days): ";
                cin >> deliveryTime;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid number." << endl;
                    continue;
                }

                break;
            }

            while (true) {
                cout << "Order Accuracy (0-1): ";
                cin >> orderAccuracy;

                if (cin.fail() || orderAccuracy < 0 || orderAccuracy > 1) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid value for Order Accuracy. Please enter a value between 0 and 1." << endl;
                    continue;
                }

                break;
            }

            while (true) {
                cout << "Product Quality (0-1): ";
                cin >> productQuality;

                if (cin.fail() || productQuality < 0 || productQuality > 1) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid value for Product Quality. Please enter a value between 0 and 1." << endl;
                    continue;
                }

                break;
            }

            while (true) {
                cout << "Lead Time (in days): ";
                cin >> leadTime;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid number." << endl;
                    continue;
                }

                break;
            }

            while (true) {
                cout << "Pricing: ";
                cin >> pricing;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid number." << endl;
                    continue;
                }

                break;
            }

            while (true) {
                cout << "Special Discount (%): ";
                cin >> specialDiscount;

                if (cin.fail() || specialDiscount < 0 || specialDiscount > 100) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid value for Special Discount. Please enter a value between 0 and 100." << endl;
                    continue;
                }

                break;
            }

            cin.ignore(); // Ignore the newline character left in the input stream

            if (specialDiscount > 0) {
                suppliers.push_back(new PreferredSupplier(name, deliveryTime, orderAccuracy, productQuality, leadTime, pricing, specialDiscount));
            } else {
                suppliers.push_back(new Supplier(name, deliveryTime, orderAccuracy, productQuality, leadTime, pricing));
            }
        }

        break;
    }

    return suppliers;
}

Supplier* findBestSupplier(const vector<Supplier*>& suppliers, double deliveryWeight, double accuracyWeight,
                          double qualityWeight, double leadTimeWeight, double pricingWeight) {
    Supplier* bestSupplier = nullptr;
    double bestScore = numeric_limits<double>::max();

    for (const auto& supplier : suppliers) {
        double score = supplier->calculateScore(deliveryWeight, accuracyWeight, qualityWeight, leadTimeWeight, pricingWeight);

        if (score < bestScore) {
            bestScore = score;
            bestSupplier = supplier;
        }
    }

    return bestSupplier;
}

int main() {
    vector<Supplier*> suppliers = getSupplierData();

    while (true) {
        double deliveryWeight;
        double accuracyWeight;
        double qualityWeight;
        double leadTimeWeight;
        double pricingWeight;

        cout << "\nEnter the weights for each metric (sum should be 1):" << endl;

        while (true) {
            cout << "Delivery Time Weight: ";
            cin >> deliveryWeight;

            if (cin.fail() || deliveryWeight < 0 || deliveryWeight > 1) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid value for Delivery Time Weight. Please enter a value between 0 and 1." << endl;
                continue;
            }

            break;
        }

        while (true) {
            cout << "Order Accuracy Weight: ";
            cin >> accuracyWeight;

            if (cin.fail() || accuracyWeight < 0 || accuracyWeight > 1) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid value for Order Accuracy Weight. Please enter a value between 0 and 1." << endl;
                continue;
            }

            break;
        }

        while (true) {
            cout << "Product Quality Weight: ";
            cin >> qualityWeight;

            if (cin.fail() || qualityWeight < 0 || qualityWeight > 1) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid value for Product Quality Weight. Please enter a value between 0 and 1." << endl;
                continue;
            }

            break;
        }

        while (true) {
            cout << "Lead Time Weight: ";
            cin >> leadTimeWeight;

            if (cin.fail() || leadTimeWeight < 0 || leadTimeWeight > 1) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid value for Lead Time Weight. Please enter a value between 0 and 1." << endl;
                continue;
            }

            break;
        }

        while (true) {
            cout << "Pricing Weight: ";
            cin >> pricingWeight;

            if (cin.fail() || pricingWeight < 0 || pricingWeight > 1) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid value for Pricing Weight. Please enter a value between 0 and 1." << endl;
                continue;
            }

            break;
        }

        double weightSum = deliveryWeight + accuracyWeight + qualityWeight + leadTimeWeight + pricingWeight;

        if (weightSum != 1.0) {
            cout << "Invalid weights. The sum of weights should be equal to 1." << endl;
            continue;
        }

        Supplier* bestSupplier = findBestSupplier(suppliers, deliveryWeight, accuracyWeight, qualityWeight, leadTimeWeight, pricingWeight);

        if (bestSupplier) {
            cout << "\nBest Supplier:" << endl;
            bestSupplier->displayDetails();
        }

        break;
    }

    
    for (const auto& supplier : suppliers) {
        delete supplier;
    }

    cout << "\nPress any key to exit...";
    cin.ignore();
    cin.get();

    return 0;
}
