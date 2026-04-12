def main():
    n,x,m = map(int,input().split())
    if n == 1:
        print(x)
        return
    
    start = x
    arr = [x]
    visited = set()
    visited.add(x)
    prev = x
    curr = pow(prev,2,m)
    while curr not in visited:
        visited.add(curr)
        arr.append(curr)
        prev = curr
        curr = pow(prev,2,m)

    total = 0
    index = 0
    while n > 0 and index < len(arr):
        total += arr[index]
        n -= 1
        index += 1

    while arr[0] != curr:
        arr.pop(0)

    total += sum(arr)*(n//len(arr))
    for i in range(n%len(arr)):
        total += arr[i]

    print(total)

main()
