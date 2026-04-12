if __name__ == "__main__":
    N = int(input())
    ryokan= input().split(" ")
    total=1
    for x in range(1,N):
        flag=True
        for y in range(x):
            if int(ryokan[x])<int(ryokan[y]):
                flag=False
                break
        if flag:
            total+=1
                
    print(total)