def main():
    n = int(input())
    s = str(input())
    k = int(input())
    

    mozi = s[k-1]
    # print(n, s , k, mozi)
    result = ''
    for c in list(s):
        if c == mozi:
            result += mozi
        else:
            result += '*'
    print(result)
    


main()