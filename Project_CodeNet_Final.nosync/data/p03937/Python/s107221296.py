h, w = [int(i) for i in input().split()]
a = [input().count("#") for i in range(h)]
print(["Impossible", "Possible"][sum(a) == h + w - 1])