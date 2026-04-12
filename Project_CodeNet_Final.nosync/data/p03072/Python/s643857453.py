if __name__ == '__main__':
    mountain_count = int(input())
    mountains = list(map(int, input().split()))
    ans = 0
    for i in range(mountain_count):
        can_watch = True
        for j in range(mountain_count):
            if i == j:
                break
            if mountains[i] < mountains[j]:
                can_watch = False
                break
        if can_watch:
            ans += 1
    print(ans)
