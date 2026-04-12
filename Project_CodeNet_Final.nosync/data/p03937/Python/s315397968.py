def main():
    h,w=map(int,input().split())
    a=[]
    for _ in range(h):
        a.append(input())
    now = (0, 0)
    end = (h-1, w-1)
    visited = set([now])
    while True:
        nxt = None
        #print(now)
        if now[0]+1 < len(a) and a[now[0]+1][now[1]] == "#":
            nxt = (now[0]+1, now[1])
        if now[1]+1 < len(a[now[0]]) and a[now[0]][now[1]+1] == "#":
            if nxt is not None:
                print("Impossible")
                return
            nxt = (now[0], now[1]+1)
        #print("next", nxt)
        if now[0]-1 >= 0 and a[now[0]-1][now[1]] == "#":
            if (now[0]-1,now[1]) not in visited:
                print("Impossible")
                return
        if now[1]-1 >= 0 and a[now[0]][now[1]-1] == "#":
            if (now[0],now[1]-1) not in visited:
                print("Impossible")
                return
        
        if now == end:
            break
        if nxt is None:
            print("Impossible")
            return
        now = nxt
        visited.add(nxt)
    print("Possible")
    
if __name__ == "__main__":
    main()