import copy
mod=10**9+7
def calc(nums,n):
    if n==2:
        return ((nums[0]%mod)*(nums[1]%mod))%mod
    cpy=copy.deepcopy(nums)    
    save=nums[n-2]
    nums[n-2]=nums[n-1]
    for i in range(n-3,-1,-1):
        s=nums[i]%mod
        nums[i]=(save%mod+nums[i+1]%mod)%mod
        save=s%mod
       
    ans=0  
    
    for i in range(n-1):
        ans=((ans%mod)  +  ((cpy[i]%mod)*(nums[i]%mod))%mod)%mod
    return ans       
    





n=int(input())
nums=list(map(int,input().split()))
print(calc(nums,n))
