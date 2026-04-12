import math
import sys
#####sorting a dictionary by the values#####
def dict_sort(ans):
    ans=sorted(ans.items(),reverse=True,key=lambda kv:(kv[1]))
##### naive method for testing prime or not#####
def is_prime(n):
    if n==1:
        return 0
    for i in range(2,int(math.sqrt(n))+1):
        if n%i==0:
            return False
    return True
#####swap function#####
def swap(a,b):
    temp=a
    a=b
    b=temp
    return a,b
#####Primes till Nth#####
def seive_primes(n):
    flag=[0]*(n+10)
    flag[1]=flag[0]=1
    i=2
    while i*i<=n+1:
        if flag[i]==0:
            j=i*i
            while j<=n+1:
                flag[j]=1
                j+=i
        i+=1
    return flag
#####function that return all combination of sum(i^n)=x#####
def checkRecursive(x, n, curr_num=1, curr_sum=0): 
    results = 0 
    p = curr_num**n 
    while(p + curr_sum < x):  
        results += checkRecursive(x, n, curr_num + 1, p + curr_sum) 
        curr_num = curr_num + 1
        p = curr_num**n  
    if(p + curr_sum == x): 
        results = results + 1
    return results
#####number of minimum swaps required to sort the array#####
def findMinSwap(arr, n): 
    vec = [] 
    for i in range(n): 
        vec.append([arr[i], i])  
    vec = sorted(vec) 
    ans, c, j = -1, 0, 0
    for i in range(n):  
        if(vec[i][1] == i): 
            continue
        else:  
            vec[i][0], vec[vec[i][1]][1] = swap(vec[i][0],vec[vec[i][1]][1])
            vec[i][1], vec[vec[i][1]][1] = swap(vec[i][1],vec[vec[i][1]][1]) 
        if(i != vec[i][1]): 
            i -= 1
        ans += 1
    return ans
#####greatest common divisor of two numbers#####
def gcd(a,b):
    if b==0:
        return a
    return gcd(b,a%b)
#####least common multiplyer of two numbers#####
def lcm(a,b):
    return (a*b)//gcd(a,b)
#####function that return all the letters#####
def alphabates():
    return "abcdefghijklmnopqrstuvwxyz"
#####binary search#####
def binary_search(ls,n,flag):
    low=0
    hi=n-1
    while(low<=hi):
        mid=(low+hi)//2
        if ls[mid]==flag:
            return mid
        elif ls[mid]>flag:
            hi=mid-1
        else:
            low=mid+1
    return -1
#####Decimal to Binary(8 bits)#####
def Binary(n):
    if n==0:
        return "00000000"
    binary = "" 
    i = 0
    while n > 0 and i<=8: 
        s1 = str(int(n%2)) 
        binary = binary + s1 
        n /= 2
        i = i+1
        d = binary[::-1] 
    return d
#####quadratic#####
def qdrt(x,a,b,c):
    return a*x*x+b*x+c
#####taking an array/list as input#####
def inp():
    ls=list(map(int,input().split()))
    return ls
#####taking multiple inputs#####
def mult_inp():
    return map(int,input().split())
#####0-1 Knapsack#####
def knapSack(W, wt, val, n): 
    K = [[0 for x in range(W + 1)] for x in range(n + 1)]  
    for i in range(n + 1): 
        for w in range(W + 1): 
            if i == 0 or w == 0: 
                K[i][w] = 0
            elif wt[i-1] <= w: 
                K[i][w] = max(val[i-1]+K[i-1][w-wt[i-1]],  K[i-1][w]) 
            else: 
                K[i][w] = K[i-1][w] 
  
    return K[n][W] 
#####Main function starts from here#####
n=int(input())
ls=inp()
ans=sum(ls)**2
sq=0
for i in range(n):
    sq+=ls[i]**2
print(((ans-sq)//2)%1000000007)
            

    
    
            

