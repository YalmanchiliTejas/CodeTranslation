def main():
    n,x,m = tuple([int(t)for t in input().split()])

    a = x
    s = a

    nextvalues = [a]
    values = set([a])

    for i in range(1,n):
        a = a*a % m
        if a in values:
            idx = nextvalues.index(a)
            size = i-idx
            sumofsubset = sum(nextvalues[idx:i])
            s += sumofsubset*((n-i)//size)+sum(nextvalues[idx:idx+(n-i)%size])
            break
        s += a
        nextvalues.append(a)
        values.add(a)
    print(s)

if __name__ == "__main__":
    main()