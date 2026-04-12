def readinput():
    n,x,m=map(int,input().split())
    return n,x,m

def main(n,x,m):
    ans_list=[]
    hist=[0]*m
    val=x
    count=0
    while hist[val]==0 and count<n:
        ans_list.append(val)
        hist[val]+=1
        val=(val*val)%m
    if count==n:
        loop_start=0
        loop_len=n
    else:
        i=0
        while ans_list[i] != val:
            i+=1
        loop_start=i
        loop_len=len(ans_list)-i 
    # print(ans_list)
    # print(loop_start)
    # print(loop_len)
    ans=sum(ans_list[:loop_start])
    ans+=sum(ans_list[loop_start:])*((n-loop_start)//loop_len)
    ans+=sum(ans_list[loop_start:loop_start+(n-loop_start)%loop_len])
    # ans=sum(ans_list)*(n//loop_len) + sum(ans_list[:n%loop_len])
    return ans

if __name__=='__main__':
    n,x,m=readinput()
    ans=main(n,x,m)
    print(ans)