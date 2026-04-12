def main():
    s = input()
    exists = s != "AAA" and s != "BBB"
    return "Yes" if exists else "No"
    


if __name__ == "__main__":
    print(main())