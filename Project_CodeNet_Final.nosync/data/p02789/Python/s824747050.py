def main():
    N, M = map(int, input().split())
    ans = 'No'

    if N==M:
        ans = 'Yes'
    
    print(ans)

if __name__ == '__main__':
    main()