if __name__ == '__main__':
    n = int(input())
    s=input()
    k=int(input())
    l=s[k-1]

    ans=""
    for i in s:
        if i == l:
            ans+=i
        else:
            ans+="*"
    print(ans)