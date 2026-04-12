

def I(): return int(input())
def MI(): return map(int, input().split())
def LI(): return list(map(int, input().split()))

def main():
    mod=10**9+7
    ans=[50]*26
    
 
    
    N=I()
    for i in range(N):
        S=input()
        temp=[0]*26
        for j in range(len(S)):
            m=ord(S[j])-97
            temp[m]+=1
        for j in range(26):
            ans[j]=min(ans[j],temp[j])
            
    res=""
    for j in range(26):
        res+=chr(j+97)*ans[j]
        
    print(res)
            
        
    
        

main()
