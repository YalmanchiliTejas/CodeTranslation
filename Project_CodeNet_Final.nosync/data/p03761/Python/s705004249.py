def main():
    n=int(input())
    s=list(input())
    dict1={}
    for i in range(len(s)):
        if s[i] not in dict1:
            dict1[s[i]]=1
        else:
            dict1[s[i]]+=1
    if n==1:
        s.sort()
        print(''.join(s))
        return
    for _ in range(n-1):
        dict2={}
        t=list(input())
        for i in range(len(t)):
            if t[i] in dict1 and dict1[t[i]]>0:
                if t[i] not in dict2:
                    dict2[t[i]]=1
                    dict1[t[i]]-=1
                else:
                    dict2[t[i]]+=1
                    dict1[t[i]]-=1
        dict1=dict2
    ans=[]
    for i in dict2:
        for _ in range(dict2[i]):
            ans.append(i)
    ans.sort()
    print(''.join(ans))
if __name__ == "__main__":
    main()