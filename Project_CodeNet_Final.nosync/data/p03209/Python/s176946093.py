def solve(level, eat_layer, all_layers, meat):
    if eat_layer == 1:
        return 0 if level > 0 else 1
    elif eat_layer <= all_layers[level - 1] + 1:
        return solve(level - 1, eat_layer - 1, all_layers, meat)
    elif eat_layer == all_layers[level - 1] + 2:
        return 1 + meat[level - 1]
    elif eat_layer <= 2 + 2 * all_layers[level - 1]:
        return 1 + meat[level - 1] + solve(level - 1, eat_layer - 2 - all_layers[level - 1], all_layers, meat)
    elif eat_layer == 3 + 2 * all_layers[level - 1]:
        return 2 * meat[level - 1] + 1


def main():
    level, eat_layer = map(int, input().split())
    level_layer = [1]
    meat = [1]
    for _ in range(level):
        level_layer.append(2 * level_layer[-1] + 3)
        meat.append(2 * meat[-1] + 1)
    print(solve(level, eat_layer, level_layer, meat))


if __name__ == '__main__':
    main()

