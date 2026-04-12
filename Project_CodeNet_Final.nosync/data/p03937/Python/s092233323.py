def main():
    h,w = map(int,input().split())
    ls = [list(input()) for _ in range(h)]
    cnt = 0
    for i in range(h):
        cnt += ls[i].count("#")
    
    if cnt == h+w-1:
        print("Possible")
    else:
        print("Impossible")
    
if __name__ == '__main__':
    main()