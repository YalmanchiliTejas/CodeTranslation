import sys
from io import StringIO
import unittest


def resolve():
    # s = input()
    n = int(input())
    a = list(map(int, input().split()))

    sum_a = sum(a)
    ans = 0

    for aa in a:
        sum_a -= aa
        ans += aa * sum_a

    print(ans % (10 ** 9 + 7))


class TestClass(unittest.TestCase):
    def assertIO(self, input, output):
        stdout, stdin = sys.stdout, sys.stdin
        sys.stdout, sys.stdin = StringIO(), StringIO(input)
        resolve()
        sys.stdout.seek(0)
        out = sys.stdout.read()[:-1]
        sys.stdout, sys.stdin = stdout, stdin
        self.assertEqual(out, output)

    def test_入力例_1(self):
        input = """3
1 2 3"""
        output = """11"""
        self.assertIO(input, output)

    def test_入力例_2(self):
        input = """4
141421356 17320508 22360679 244949"""
        output = """437235829"""
        self.assertIO(input, output)


if __name__ == "__main__":
    # unittest.main()
    resolve()
