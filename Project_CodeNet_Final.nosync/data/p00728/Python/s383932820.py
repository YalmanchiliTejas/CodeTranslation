while True:
    judges = int(input())
    if not judges:
        break
    a = [int(input()) for i in range(judges)]
    a.remove(max(a))
    a.remove(min(a))
    print(int(sum(a) / len(a)))