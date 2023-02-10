/*
 * Program2.c
 *
 *  Created on: Feb 8, 2023
 *      Author: e450b680
 */
#include <stdio.h>
#define TOUCHDOWN_W_2PT 8
#define TOUCHDOWN_W_1PT 7
#define TOUCHDOWN 6
#define FIELD_GOAL 3
#define SAFETY 2

int main()
{
  int points = -1;
  while (points != 0 && points != 1)
  {
    printf("\nEnter 0 or 1 to STOP\nEnter the NFL score: ");
    scanf("%d", &points);
    if (points > 1)
      printf("possible combinations of scoring plays: \n");
    for (int td2 = points / TOUCHDOWN_W_2PT; td2 >= 0; td2--)
    {
      int td2Points = points - td2 * TOUCHDOWN_W_2PT;

      for (int td1 = td2Points / TOUCHDOWN_W_1PT; td1 >= 0; td1--)
      {
        int td1Points = td2Points - td1 * TOUCHDOWN_W_1PT;

        for (int td = td1Points / TOUCHDOWN; td >= 0; td--)
        {
          int tdPoints = td1Points - td * TOUCHDOWN;

          for (int fg = tdPoints / FIELD_GOAL; fg >= 0; fg--)
          {
            int fgPoints = tdPoints - fg * FIELD_GOAL;

            for (int safe = fgPoints / SAFETY; safe >= 0; safe--)
            {
              int safePoints = fgPoints - safe * SAFETY;

              if (safePoints == 0)
              {
                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety.\n",
                       td2, td1, td, fg, safe);
              }
            }
          }
        }
      }
    }
  }

  return 0;
}