import copy
n, m = map(int,input().split())
graph = []
num = 1
for i in range(m):
    graph.append(list(map(int, input().split())))
pathes = [[[1],graph]]
count = 0
while pathes:
    path_lines = pathes.pop()
    path, lines = path_lines
    if len(path) == n:
        count += 1
    else:
        for line in lines:
            if path[-1] in line:
                new_path = copy.copy(path)
                new_lines = copy.copy(lines)
                new_lines.remove(line)
                new_line = copy.copy(line)
                new_line.remove(new_path[-1])
                
                if new_line[0] in new_path:
                    continue
                new_path.append(new_line[0])
                pathes.append([new_path, new_lines])
print(count)