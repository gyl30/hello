#include <iostream>
#include <range/v3/all.hpp>
#include <boost/asio.hpp>

int main(int argc, char* argv[])
{
    boost::asio::io_context io_context;

    io_context.post(
        []
        {
            std::vector<int> numbers{1, 2, 3, 4};

            auto even =
                ranges::views::take(numbers, 3) | ranges::views::filter([](const int& num) { return num % 2 == 0; });
            std::cout << even << '\n';
        });
    io_context.run();
    return 0;
}
