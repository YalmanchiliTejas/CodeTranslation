def main():
    a = [input() for _ in range(int(input()))]
    common = ""
    for x in "abcdefghijklmnopqrstuvwxyz":
        common += x * min((i.count(x) for i in a))
    print(common)
        
if __name__ == "__main__":
    main()