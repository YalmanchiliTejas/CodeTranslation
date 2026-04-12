def buy_ab(cost_a, cost_b, cost_ab, target_a, target_b, target_ab):
    target_a = max(0, target_a - target_ab // 2)
    target_b = max(0, target_b - target_ab // 2)
    return cost_ab * target_ab + cost_a *target_a  + cost_b * target_b


def main():
    cost_a, cost_b, cost_ab, target_a, target_b = map(int, input().split(" "))
    buy_whole = cost_a * target_a + cost_b * target_b
    print(min(buy_ab(cost_a, cost_b, cost_ab, target_a, target_b, min(target_b, target_a) * 2),
              buy_ab(cost_a, cost_b, cost_ab, target_a, target_b, max(target_b, target_a) * 2),
              buy_whole))


if __name__ == '__main__':
    main()