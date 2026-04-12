h, w = map(int, input().split())
c = sum([input().count("#") for _ in range(h)])
print("Possible" if h + w - 1 == c else "Impossible")
