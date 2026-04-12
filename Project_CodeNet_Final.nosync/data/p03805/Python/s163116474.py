num_route = 0
num_node = 0

def func(unvisited_paths, visited_node, current_node):
    global num_route
    if len(visited_node) == num_node:
            num_route += 1
            return
    for next_path in [path for path in unvisited_paths if (path[0] == current_node) and (path[1] not in visited_node)]:
        next_visited_node = visited_node + [next_path[1]]
        next_unvisited_paths = unvisited_paths[:]
        next_unvisited_paths.pop(next_unvisited_paths.index([current_node, next_path[1]]))
        next_unvisited_paths.pop(next_unvisited_paths.index([next_path[1], current_node]))
        next_current_node = next_path[1]
        
        func(next_unvisited_paths, next_visited_node, next_current_node)
    
    return

def main():
    global num_node
    num_node, num_path = map(int, input().split())
    unvisited_paths = [list(map(int, input().split())) for i in range(num_path)]
    for path in unvisited_paths[:]:
        unvisited_paths.append([path[1], path[0]])
    current_node, visited_node = 1, [1]
    func(unvisited_paths, visited_node, current_node)
    print(num_route)

if __name__ == '__main__':
    main()