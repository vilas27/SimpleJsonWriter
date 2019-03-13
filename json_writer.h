#include <string>

class JsonWriter
{
  public:
    JsonWriter()
    {
        json_string = "";
    }
    ~JsonWriter()
    {
        json_string = "";
    }

    void Reset()
    {
        json_string = "";
    }

    void OpenObject()
    {
        json_string += "{";
    }

    void CloseObject()
    {
        Check();
        json_string += "},";
    }

    void OpenArray(std::string key)
    {
        json_string += "\"" + key + "\":" + "[";
    }
    void CloseArray()
    {
        Check();
        json_string += "],";
    }

    void Add(std::string key, std::string value)
    {
        json_string += "\"" + key + "\":\'" + value + "\',";
    }

    void Add(std::string key, int value)
    {
        json_string += "\"" + key + "\":" + std::to_string(value) + ",";
    }

    void Add(std::string key, long long value)
    {
        json_string += "\"" + key + "\":" + std::to_string(value) + ",";
    }

    void Add(std::string key, float value)
    {
        json_string += "\"" + key + "\":" + std::to_string(value) + ",";
    }

    std::string Get()
    {
        Check();
        return json_string;
    }

  private:
    std::string json_string;

    void Check()
    {
        if (json_string.back() == ',')
        {
            json_string.pop_back();
        }
    }
};
