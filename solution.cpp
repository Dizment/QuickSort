using System;

namespace QuickSort
{
    public static class Sorter
    {
        public static void QuickSort(this int[] array)
        {
            if (array is null)
            {
                throw new ArgumentNullException(nameof(array));
            }

            if (array.Length == 0)
            {
                return;
            }

            long i, j, left, right;

            long[] leftStack = new long[100];
            long[] rightStack = new long[100];

            long stackCurrent = 1;
            long mid;
            int pivot;
            int temp;

            leftStack[1] = 0;
            rightStack[1] = array.Length - 1;

            do
            {
                left = leftStack[stackCurrent];
                right = rightStack[stackCurrent];
                stackCurrent--;

                do
                {
                    mid = (left + right) / 2;
                    i = left;
                    j = right;
                    pivot = array[mid];

                    do
                    {
                        while (array[i] < pivot)
                        {
                            i++;
                        }

                        while (array[j] > pivot)
                        {
                            j--;
                        }

                        if (i <= j)
                        {
                            temp = array[i];
                            array[i] = array[j];
                            array[j] = temp;
                            i++;
                            j--;
                        }
                    }
                    while (i <= j);

                    if (i < mid)
                    {
                        if (i < right)
                        {
                            stackCurrent++;
                            leftStack[stackCurrent] = i;
                            rightStack[stackCurrent] = right;
                        }

                        right = j;
                    }
                    else
                    {
                        if (j > left)
                        {
                            stackCurrent++;
                            leftStack[stackCurrent] = left;
                            rightStack[stackCurrent] = j;
                        }

                        left = i;
                    }
                }
                while (left < right);
            }
            while (stackCurrent != 0);
        }

        public static void RecursiveQuickSort(this int[] array)
        {
            if (array is null)
            {
                throw new ArgumentNullException(nameof(array));
            }

            if (array.Length == 0)
            {
                return;
            }

            QuickSortRec(array, 0, array.Length - 1);
        }

        public static void QuickSortRec(int[] array, int first, int last)
        {
            if (array is null)
            {
                throw new ArgumentNullException(nameof(array));
            }

            int i = first, j = last;
            int mid = (i + j) / 2;
            int pivot = array[mid];

            do
            {
                while (array[i] < pivot)
                {
                    i++;
                }

                while (array[j] > pivot)
                {
                    j--;
                }

                if (i <= j)
                {
                    int temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                    i++;
                    j--;
                }
            }
            while (i < j);

            if (first < j)
            {
                QuickSortRec(array, first, j);
            }

            if (i < last)
            {
                QuickSortRec(array, i, last);
            }
        }
    }
}
