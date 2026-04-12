# row = [int(x) for x in input().rstrip().split(" ")]
# n = int(input().rstrip())
# s = input().rstrip()

def resolve():
    import sys
    input = sys.stdin.readline

    a, b, c, x, y = [int(x) for x in input().rstrip().split(" ")]

    a_count = 0
    b_count = 0
    ab_count = 0
    if a + b > 2 * c:
        # abのが割安なら、買えるだけabを買う
        min_pizza = min(x,y)
        ab_count += min_pizza * 2
        x = x - min_pizza
        y = y - min_pizza

    # aを買う
    if c * 2 < a:
        # abでaを用意した方が安いなら
        ab_count += x * 2
    else:
        # aでaを買う
        a_count += x

    # bを買う
    if c * 2 < b:
        # abでbを用意した方が安いなら
        ab_count += y * 2
    else:
        # aでaを買う
        b_count += y

    print(a_count * a + b_count * b + ab_count * c)


if __name__ == "__main__":
    resolve()
