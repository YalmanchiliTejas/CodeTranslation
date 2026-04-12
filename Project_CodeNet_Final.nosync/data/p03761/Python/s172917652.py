def main():
    n=int(input())
    cnt=[50]*26
    tmp=[0]*26
    for i in range(n):
        s=input()
        for j in range(len(s)):
            tmp[ord(s[j])-97]+=1
        for j in range(26):
            cnt[j]=min(cnt[j],tmp[j])
            tmp[j]=0
    ans=""
    for i in range(26):
        if cnt[i]!=0:
            ans+=chr(97+i)*cnt[i]
    print(ans)
if __name__=="__main__":
    main()