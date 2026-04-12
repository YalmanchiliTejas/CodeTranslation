def main():
    n,m = map(int,input().split())
    maze=[]
    for _ in range(n):
        maze.append(list(input()))
    cnt=0
    for i in range(n):
        for j in range(m):
            if maze[i][j]=="#":
                cnt+=1
    if cnt==n+m-1:print("Possible")
    else:print("Impossible")
    
main()