#include <map>
#include <vector>
#include <iostream>
#include <algorithm>


class Point {
private:
    int day;
    int hour;
    int minute;
    char status;
public:

    Point(int day, int hour, int minute, char status) : day(day), hour(hour), minute(minute), status(status) {}

    int get_day() { return this->day; }
    int get_hour() { return this->hour; }
    int get_minute() { return this->minute; }
    int get_status() { return this->status; }

    int get_minutes() {
        return get_day() * 60 * 24 + get_hour() * 60 + get_minute();
    }

    
};

bool comp(Point& lhs, Point& rhs) {
    return lhs.get_minutes() < rhs.get_minutes();
}



int main()
{
    int N;
    std::cin >> N;
    std::map<int, std::vector<Point>> points;
    std::vector<int> result;

    for (int i = 0; i < N; ++i) {
        int day, hour, minute, rocket_id;
        char status;
        
        std::cin >> day >> hour >> minute >> rocket_id >> status;

        auto point = Point(day, hour, minute, status);

        points[rocket_id].push_back(point);
    }

    for (auto& el : points) {
        int temp_result = 0;
        std::sort(el.second.begin(), el.second.end(), comp);

        for (size_t j = 0; j < el.second.size(); ++j) {
            if (el.second[j].get_status() == 'A') {
                temp_result -= el.second[j].get_minutes();          
            }

            else if (el.second[j].get_status() == 'S' || el.second[j].get_status() == 'C') {
                temp_result += el.second[j].get_minutes();
            }
        }

        result.push_back(temp_result);
    }

    for (const auto& el : result) {
        std::cout << el << " ";
    }
    return EXIT_SUCCESS;
}

