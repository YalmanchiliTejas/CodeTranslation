def main():
    a,b,c,x,y = map(int, input().split())
    ans = 10**10
    for i in range(max(x, y)+1):
        total = i*2*c + max(0, x-i)*a + max(0, y-i)*b
        ans = min(ans, total)
    print(ans)


    
if __name__ == '__main__':
    main()