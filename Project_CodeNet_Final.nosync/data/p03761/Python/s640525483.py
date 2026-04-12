def main():
    n = int(input())
    indic = dict()

    s = input()
    slen = len(s)
    for i in range(slen):
        a = s[i]
        if a in indic:
            indic[a] += 1
        else:
            indic[a] = 1
    

    for _ in range(1, n):
        s = input()
        slen = len(s)
        sdic = dict()
        tmplis=list()
        for i in range(slen):
            a = s[i]
            if a in sdic:
                sdic[a] += 1
            else:
                sdic[a] = 1

        for key in indic:
            if key not in sdic:
                tmplis.append(key)
            else:
                if indic[key] > sdic[key]:
                    indic[key] = sdic[key]

        for word in tmplis:
            indic.pop(word) 

    anslis = list()
    indic = sorted(indic.items())

    for j in range(len(indic)):
        a = indic[j][0]
        num = indic[j][1]
        anslis.append(a * num)
    print(*anslis, sep="")


if __name__ == "__main__":
    main()