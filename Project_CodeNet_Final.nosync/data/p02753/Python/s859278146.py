import argparse

def main(s: str):
    if s[0] == s[1] == s[2]:
        return "No"
    else:
        return "Yes"

if __name__ == "__main__":
    s = input()
    print(main(s))