def main():
    n,x,m=map(int,input().split())
    visited=[0]*m
    visit_sum=[0]*m
    i=1
    sm=x
    visited[x]=1
    visit_sum[x]=x
    work=x
    while i < n:
        work**=2
        work%=m
        sm+=work
        i+=1
#        print(sm,work)
        if not visited[work]:
            visited[work]=i
            visit_sum[work]=sm
        else :
            break
    else :
        print(sm)
        exit()
    loop_sum=sm-visit_sum[work]
    loop_num=i-visited[work]
    if visited[work]!=1: 
        initial_sum=visit_sum[visited.index(visited[work]-1)]
    else :
        initial_sum=0

    out=initial_sum
#    print(out)
    out+=(n-visited[work]+1)//loop_num*loop_sum
#    print(out)
    work_num=(n-visited[work]+1)%loop_num
    if work_num>0:
        out+=visit_sum[visited.index(visited[work]-1+work_num)]-initial_sum
        
    print(out)

main()
