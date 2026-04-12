from sys import stdin
import numpy as np
def main():
    #入力
    readline=stdin.readline
    n=int(readline())
    s=[readline().strip() for _ in range(n)]

    for i in range(n):
        if i==0:
            alp=np.zeros(26,dtype=np.int64)
            t=s[i]
            for j in range(len(t)):
                alp[ord(t[j])-97]+=1
        else:
            tmp=np.zeros(26,dtype=np.int64)
            t=s[i]
            for j in range(len(t)):
                tmp[ord(t[j])-97]+=1
            alp=np.minimum(alp,tmp)

    ans=""
    for i in range(26):
        if alp[i]>=1:
            ans+=chr(i+97)*alp[i]

    print(ans)

if __name__=="__main__":
    main()