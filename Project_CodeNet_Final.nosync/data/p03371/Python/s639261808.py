def main():
    A, B, AB, x, y = map(int, input().split())
    ans = []
    ans.append(A*x + B*y)
    if x < y:
        ans.append(AB*x*2 + B*(y-x))
        ans.append(AB*y*2)
    elif y < x:
        ans.append(AB*y*2 + A*(x-y))
        ans.append(AB*x*2)
    else:
        ans.append(AB*x*2)
    print(min(ans))


if __name__ == "__main__":
    main()