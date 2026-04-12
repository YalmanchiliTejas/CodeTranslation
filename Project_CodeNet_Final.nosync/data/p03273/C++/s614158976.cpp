# if true

# include <iostream>
# include <string>
# include <vector>

int main()
{

    int H, W;
    std::cin >> H >> W;

    std::vector<std::string> data(H);
    for (auto& val : data) std::cin >> val;

    std::vector<std::string> result{};
    for (auto& val : data)
    {
        bool empty{true};
        for (auto& c : val)
            if (c != '.') empty = false;

        if (!empty)
            result.emplace_back(val);
    }

    if(!result.empty())
        for (bool noloop{}; !noloop;)
        {
            noloop = true;

            for (int x{}; x < result.front().size(); ++x)
            {
                bool empty{ true };
                for (int i{}; i < result.size(); ++i)
                {
                    if (result[i][x] != '.') empty = false;
                }

                if (empty)
                {
                    for (auto& str : result)
                        str.erase(str.begin() + x);
                    
                    noloop = false;
                    break;
                }
            }
        
        }


    for (auto& str : result)
        std::cout << str << std::endl;



    return 0;
}

# endif