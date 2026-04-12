# coding: utf-8

def main():
    s = input().strip()
    for i in range(len(s)-1):
        if s[i:i + 2] == "AC":
            return "Yes"
    return "No"


if __name__ == "__main__":
    print(main())
