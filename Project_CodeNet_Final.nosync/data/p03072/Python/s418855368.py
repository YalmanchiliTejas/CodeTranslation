def test():
    n = int(input())
    a = list(map(int,input().split()))
    b = [a[0]]
    count = 1
    for i in range(1,n):
        for j in range(i):
            b.append(a[j])
        if all(x <= a[i] for x in b):
            count += 1

    print(count)


if __name__ == "__main__":
    test()
