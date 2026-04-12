H, W = [int(i) for i in input().split()]
maze = [list(input()) for _ in range(H)]
maze = [l for l in maze if "#" in l]
maze = list(zip(*maze))
maze = [l for l in maze if "#" in l]
maze = list(zip(*maze))
maze = ["".join(l) for l in maze]
print(*maze, sep="\n")