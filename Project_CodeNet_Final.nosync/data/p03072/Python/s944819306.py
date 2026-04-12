def main():
    n = input()
    s = input()
    raw_list = list(map(int, s.split()))

    max = raw_list[0]
    count = 1

    for i in range(1,len(raw_list)):
        if raw_list[i] >= max:
            count += 1
            max = raw_list[i]
    print (count)

if __name__ == "__main__":
    main()