def main():
    H,W = map(int,input().split())
    strings = []

    for h in range(H):
        inp = input()
        if not "#" in inp:
            continue
        strings.append(inp)


    #横の行が消えてるかテスト
    #print("")
    #for s in strings:
    #    print(s)

    delete_row = [False] * W
    for i in range(W):
        if all([string[i]=="." for string in strings]):
            delete_row[i] =True


    #filter
    new_strings = []
    for string in strings:
        temp_s = ""
        for i,c in enumerate(string):
            if not delete_row[i]:
                temp_s = temp_s + c
        new_strings.append(temp_s)
    #print()


    for string in new_strings:
        print(string)











if __name__ == '__main__':
    main()
