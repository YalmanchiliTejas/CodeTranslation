b = False
while True:
    n = int(input())
    if n == 0:
        break
    dataset = []
    if b:
        print()
    b = True
    for _ in range(n):
        name, w, l, d = input().split()
        dataset.append((name, 3*int(w) + int(d), n-len(dataset)))
    for name, score, _ in sorted(dataset, key=lambda x: (x[1], x[2]))[::-1]:
        print(name + "," + str(score))