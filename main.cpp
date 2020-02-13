#include <iostream>
#include <array>
#include <map>
#include <assert.h>
#include <memory>
#include <vector>
#include <fstream>
#ifndef ONLINE_JUDGE
#include <boost/algorithm/string/trim.hpp>
#include <sstream>
#endif
#include <iomanip>

std::map<char,char> get_memorable_char_to_standard_mappings()
{
    std::map<char, char> result;
    // standard mappings
    result['0'] = '0';
    result['1'] = '1';
    result['2'] = '2';
    result['3'] = '3';
    result['4'] = '4';
    result['5'] = '5';
    result['6'] = '6';
    result['7'] = '7';
    result['8'] = '8';
    result['9'] = '9';

    // memorable char mappings
    result['A'] = '2';
    result['B'] = '2';
    result['C'] = '2';

    result['D'] = '3';
    result['E'] = '3';
    result['F'] = '3';

    result['G'] = '4';
    result['H'] = '4';
    result['I'] = '4';

    result['J'] = '5';
    result['K'] = '5';
    result['L'] = '5';

    result['M'] = '6';
    result['N'] = '6';
    result['O'] = '6';

    result['P'] = '7';
    result['R'] = '7';
    result['S'] = '7';

    result['T'] = '8';
    result['U'] = '8';
    result['V'] = '8';

    result['W'] = '9';
    result['X'] = '9';
    result['Y'] = '9';
    return result;
}

std::string translate_memorable_tel_to_standard(const std::string & memorable_tel)
{
    static const auto char_mappings = get_memorable_char_to_standard_mappings();
    std::string result;
    for (auto element : memorable_tel)
    {
        auto iter = char_mappings.find(element);

        if (iter != char_mappings.end())
        {
            if (result.size() == 3)
                result.push_back('-');

            result.push_back(iter->second);
        }
    }
    return result;
}

std::vector<std::string> read_input_memorable_tels(std::istream & in)
{
    std::vector<std::string> result;
    size_t count(0);
    in >> count;
    for (size_t i = 0; i < count; ++i)
    {
        std::string tel;
        in >> tel;
        result.push_back(tel);
    }
    return result;
}

void process_dataset(std::istream & in, std::ostream & out)
{
    std::map<std::string, int> tel_counter;
    std::vector<std::string> memorable_tels = read_input_memorable_tels(in);
    for (const auto & memorable_tel : memorable_tels)
    {
        std::string standard_tel = translate_memorable_tel_to_standard(memorable_tel);
        tel_counter[standard_tel]++;
    }

    // print result
    if (tel_counter.size() == memorable_tels.size())
    {
        out << "No duplicates." << std::endl;
    }
    else
    {
        for (const auto & ele : tel_counter)
        {
            if (ele.second > 1)
            {
                out << ele.first << " " << ele.second << std::endl;
            }
        }
    }
    out << std::endl;
}

void run(std::istream & in, std::ostream & out)
{
    size_t dataset_count(0);
    in >> dataset_count;
    for (size_t dataset_index = 0 ; dataset_index < dataset_count ; ++dataset_index)
    {
        process_dataset(in, out);
    }
}

#ifdef ONLINE_JUDGE

int main(int argc, char** argv)
{
    run(std::cin, std::cout);
    return 0;
}

#else

int main(int argc, char** argv)
{
    std::ifstream stream_in("input.txt");
    std::stringstream stream_out;
    run(stream_in, stream_out);

    std::string my_answer = stream_out.str();
    std::ifstream t("output.txt");
    std::string expected_answer((std::istreambuf_iterator<char>(t)),
        std::istreambuf_iterator<char>());

    BOOST_ASSERT(boost::trim_right_copy(my_answer) == boost::trim_right_copy(expected_answer));
    return 0;
}
#endif
