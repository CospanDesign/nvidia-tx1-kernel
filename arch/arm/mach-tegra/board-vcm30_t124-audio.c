/*
 * arch/arm/mach-tegra/board-vcm30t124-audio.c
 *
 * Copyright (c) 2014, NVIDIA CORPORATION.  All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <sound/soc.h>
#include <mach/tegra_vcm30t124_pdata.h>
#include <mach/board_id.h>
#include "board.h"

#define TDM_SLOT_MAP(stream_id, nth_channel, nth_byte)	\
	((stream_id << 16) | (nth_channel << 8) | nth_byte)

static unsigned int tegra_vcm30t124_amx_slot_map[] = {
	/* jack 0 */
	TDM_SLOT_MAP(0, 0, 0),
	TDM_SLOT_MAP(0, 0, 0),
	TDM_SLOT_MAP(0, 1, 0),
	TDM_SLOT_MAP(0, 1, 1),
	TDM_SLOT_MAP(0, 0, 0),
	TDM_SLOT_MAP(0, 0, 0),
	TDM_SLOT_MAP(0, 2, 0),
	TDM_SLOT_MAP(0, 2, 1),
	/* jack 1 */
	TDM_SLOT_MAP(0, 0, 0),
	TDM_SLOT_MAP(0, 0, 0),
	TDM_SLOT_MAP(1, 1, 0),
	TDM_SLOT_MAP(1, 1, 1),
	TDM_SLOT_MAP(0, 0, 0),
	TDM_SLOT_MAP(0, 0, 0),
	TDM_SLOT_MAP(1, 2, 0),
	TDM_SLOT_MAP(1, 2, 1),
	/* jack 2 */
	TDM_SLOT_MAP(0, 0, 0),
	TDM_SLOT_MAP(0, 0, 0),
	TDM_SLOT_MAP(2, 1, 0),
	TDM_SLOT_MAP(2, 1, 1),
	TDM_SLOT_MAP(0, 0, 0),
	TDM_SLOT_MAP(0, 0, 0),
	TDM_SLOT_MAP(2, 2, 0),
	TDM_SLOT_MAP(2, 2, 1),
	/* jack 3 */
	TDM_SLOT_MAP(0, 0, 0),
	TDM_SLOT_MAP(0, 0, 0),
	TDM_SLOT_MAP(3, 1, 0),
	TDM_SLOT_MAP(3, 1, 1),
	TDM_SLOT_MAP(0, 0, 0),
	TDM_SLOT_MAP(0, 0, 0),
	TDM_SLOT_MAP(3, 2, 0),
	TDM_SLOT_MAP(3, 2, 1),
};

static unsigned int tegra_vcm30t124_adx_slot_map[] = {
	/* jack 0 */
	TDM_SLOT_MAP(0, 0, 0),
	TDM_SLOT_MAP(0, 0, 0),
	TDM_SLOT_MAP(0, 1, 0),
	TDM_SLOT_MAP(0, 1, 1),
	TDM_SLOT_MAP(0, 0, 0),
	TDM_SLOT_MAP(0, 0, 0),
	TDM_SLOT_MAP(0, 2, 0),
	TDM_SLOT_MAP(0, 2, 1),
	/* jack 1 */
	TDM_SLOT_MAP(0, 0, 0),
	TDM_SLOT_MAP(0, 0, 0),
	TDM_SLOT_MAP(1, 1, 0),
	TDM_SLOT_MAP(1, 1, 1),
	TDM_SLOT_MAP(0, 0, 0),
	TDM_SLOT_MAP(0, 0, 0),
	TDM_SLOT_MAP(1, 2, 0),
	TDM_SLOT_MAP(1, 2, 1),
	/* jack 2 */
	TDM_SLOT_MAP(0, 0, 0),
	TDM_SLOT_MAP(0, 0, 0),
	TDM_SLOT_MAP(2, 1, 0),
	TDM_SLOT_MAP(2, 1, 1),
	TDM_SLOT_MAP(0, 0, 0),
	TDM_SLOT_MAP(0, 0, 0),
	TDM_SLOT_MAP(2, 2, 0),
	TDM_SLOT_MAP(2, 2, 1),
	/* jack 3 */
	TDM_SLOT_MAP(0, 0, 0),
	TDM_SLOT_MAP(0, 0, 0),
	TDM_SLOT_MAP(3, 1, 0),
	TDM_SLOT_MAP(3, 1, 1),
	TDM_SLOT_MAP(0, 0, 0),
	TDM_SLOT_MAP(0, 0, 0),
	TDM_SLOT_MAP(3, 2, 0),
	TDM_SLOT_MAP(3, 2, 1),
};

struct snd_soc_pcm_stream tegra_vcm30t124_amx_input_params[] = {
	[0] = {
		.formats = SNDRV_PCM_FMTBIT_S16_LE,
		.rate_min = 48000,
		.rate_max = 48000,
		.channels_min = 2,
		.channels_max = 2,
	},
	[1] = {
		.formats = SNDRV_PCM_FMTBIT_S16_LE,
		.rate_min = 48000,
		.rate_max = 48000,
		.channels_min = 2,
		.channels_max = 2,
	},
	[2] = {
		.formats = SNDRV_PCM_FMTBIT_S16_LE,
		.rate_min = 48000,
		.rate_max = 48000,
		.channels_min = 2,
		.channels_max = 2,
	},
	[3] = {
		.formats = SNDRV_PCM_FMTBIT_S16_LE,
		.rate_min = 48000,
		.rate_max = 48000,
		.channels_min = 2,
		.channels_max = 2,
	},
};

struct snd_soc_pcm_stream tegra_vcm30t124_adx_input_params[] = {
	[0] = {
		.formats = SNDRV_PCM_FMTBIT_S16_LE,
		.rate_min = 48000,
		.rate_max = 48000,
		.channels_min = 2,
		.channels_max = 2,
	},
	[1] = {
		.formats = SNDRV_PCM_FMTBIT_S16_LE,
		.rate_min = 48000,
		.rate_max = 48000,
		.channels_min = 2,
		.channels_max = 2,
	},
	[2] = {
		.formats = SNDRV_PCM_FMTBIT_S16_LE,
		.rate_min = 48000,
		.rate_max = 48000,
		.channels_min = 2,
		.channels_max = 2,
	},
	[3] = {
		.formats = SNDRV_PCM_FMTBIT_S16_LE,
		.rate_min = 48000,
		.rate_max = 48000,
		.channels_min = 2,
		.channels_max = 2,
	},
};

static const struct snd_soc_dapm_route tegra_e1860_a0x_audio_map[] = {
	{"Headphone-y",	NULL,	"y DAC1OUT"},
	{"Headphone-y", NULL,	"y DAC2OUT"},
	{"Headphone-y",	NULL,	"y DAC3OUT"},
	{"Headphone-y", NULL,	"y DAC4OUT"},
	{"y ADC1IN",	NULL,	"LineIn-y"},
	{"y ADC2IN",	NULL,	"LineIn-y"},
	{"Headphone-x",	NULL,	"x ROUT"},
	{"Headphone-x",	NULL,	"x LOUT"},
	{"x LLINEIN",	NULL,	"LineIn-x"},
	{"x RLINEIN",	NULL,	"LineIn-x"},
	{"Spdif-out",	NULL,	"z OUT"},
	{"z IN",	NULL,	"Spdif-in"},
};

static const struct snd_soc_dapm_route tegra_e1860_b00_audio_map[] = {
	{"Headphone-x",	NULL,	"x DACOUT1"},
	{"Headphone-x",	NULL,	"x DACOUT2"},
	{"Headphone-x",	NULL,	"x DACOUT3"},
	{"Headphone-x",	NULL,	"x DACOUT4"},
	{"Headphone-x",	NULL,	"x DACOUT5"},
	{"Headphone-x",	NULL,	"x DACOUT6"},
	{"Mic-x", NULL, "x MICBIAS"},
	{"x IN1",	NULL,	"Mic-x"},
	{"x IN2",	NULL,	"Mic-x"},
	{"x IN3",	NULL,	"Mic-x"},
	{"x IN4",	NULL,	"Mic-x"},
	{"x IN5",	NULL,	"Mic-x"},
	{"x IN6",	NULL,	"Mic-x"},
	{"Headphone-y",	NULL,	"y DAC1OUT"},
	{"Headphone-y", NULL,	"y DAC2OUT"},
	{"Headphone-y",	NULL,	"y DAC3OUT"},
	{"Headphone-y", NULL,	"y DAC4OUT"},
	{"y ADC1IN",	NULL,	"LineIn-y"},
	{"y ADC2IN",	NULL,	"LineIn-y"},
	{"Spdif-out",	NULL,	"z OUT"},
	{"z IN",	NULL,	"Spdif-in"},
};

static const struct snd_soc_dapm_route tegra_voice_call_audio_map[] = {
	{"Headphone-x",	NULL,	"x DACOUT1"},
	{"Headphone-x",	NULL,	"x DACOUT2"},
	{"Headphone-x",	NULL,	"x DACOUT3"},
	{"Headphone-x",	NULL,	"x DACOUT4"},
	{"Headphone-x",	NULL,	"x DACOUT5"},
	{"Headphone-x",	NULL,	"x DACOUT6"},
	{"Mic-x", NULL, "x MICBIAS"},
	{"x IN1",	NULL,	"Mic-x"},
	{"x IN2",	NULL,	"Mic-x"},
	{"x IN3",	NULL,	"Mic-x"},
	{"x IN4",	NULL,	"Mic-x"},
	{"x IN5",	NULL,	"Mic-x"},
	{"x IN6",	NULL,	"Mic-x"},
	{"Spdif-out",	NULL,	"y OUT"},
	{"y IN",	NULL,	"Spdif-in"},
};

static struct tegra_vcm30t124_platform_data tegra_e1860_a0x_pdata = {
	/* initialize DAI link config */
	.dai_config[0] = {
		.cpu_name = "tegra30-i2s.0",
		.codec_name = "wm8731.0-001a",
		.codec_dai_name = "wm8731-hifi",
		.cpu_dai_name = "I2S0",
		.codec_prefix = "x",
		.dai_fmt = SND_SOC_DAIFMT_I2S |
			SND_SOC_DAIFMT_NB_NF |
			SND_SOC_DAIFMT_CBS_CFS,
		.params.formats = SNDRV_PCM_FMTBIT_S16_LE,
		.params.rate_min = 48000,
		.params.rate_max = 48000,
		.params.channels_min = 2,
		.params.channels_max = 2,
	},
	.dai_config[1] = {
		.cpu_name = "tegra30-i2s.4",
		.codec_name = "ad193x.0-0007",
		.codec_dai_name = "ad193x-hifi",
		.cpu_dai_name = "I2S4",
		.codec_prefix = "y",
		.dai_fmt = SND_SOC_DAIFMT_DSP_A |
			SND_SOC_DAIFMT_NB_NF |
			SND_SOC_DAIFMT_CBM_CFM,
		.params.formats = SNDRV_PCM_FMTBIT_S32_LE,
		.params.rate_min = 48000,
		.params.rate_max = 48000,
		.params.channels_min = 8,
		.params.channels_max = 8,
	},
	.dai_config[2] = {
		.cpu_name = "tegra30-spdif",
		.codec_name = "spdif-dit.0",
		.codec_dai_name = "dit-hifi",
		.cpu_dai_name = "SPDIF",
		.codec_prefix = "z",
		.params.formats = SNDRV_PCM_FMTBIT_S16_LE,
		.params.rate_min = 48000,
		.params.rate_max = 48000,
		.params.channels_min = 2,
		.params.channels_max = 2,
	},
	.dev_num = 3,
	/* initialize AMX config */
	.amx_config[0] = {
		.slot_map = tegra_vcm30t124_amx_slot_map,
		.params = tegra_vcm30t124_amx_input_params,
	},
	.amx_config[1] = {
		.slot_map = tegra_vcm30t124_amx_slot_map,
		.params = tegra_vcm30t124_amx_input_params,
	},
	.num_amx = 2,
	/* initialize ADX config */
	.adx_config[0] = {
		.slot_map = tegra_vcm30t124_adx_slot_map,
		.params = tegra_vcm30t124_adx_input_params,
	},
	.adx_config[1] = {
		.slot_map = tegra_vcm30t124_adx_slot_map,
		.params = tegra_vcm30t124_adx_input_params,
	},
	.num_adx = 2,
	/* initialize DAPM routes */
	.dapm_routes = tegra_e1860_a0x_audio_map,
	.num_dapm_routes = ARRAY_SIZE(tegra_e1860_a0x_audio_map),
	/* sound card: tegra-wm8731-ad1937 */
	.card_name = "tegra-wm-ad",
};

static struct tegra_vcm30t124_platform_data tegra_e1860_b00_pdata = {
	/* intialize DAI link config */
	.dai_config[0] = {
		.cpu_name = "tegra30-i2s.0",
		.codec_name = "ak4618.0-0010",
		.codec_dai_name = "ak4618-hifi",
		.cpu_dai_name = "I2S0",
		.codec_prefix = "x",
		.dai_fmt = SND_SOC_DAIFMT_DSP_A |
			SND_SOC_DAIFMT_NB_NF |
			SND_SOC_DAIFMT_CBS_CFS,
		.params.formats = SNDRV_PCM_FMTBIT_S32_LE,
		.params.rate_min = 48000,
		.params.rate_max = 48000,
		.params.channels_min = 8,
		.params.channels_max = 8,
	},
	.dai_config[1] = {
		.cpu_name = "tegra30-i2s.4",
		.codec_name = "ad193x.0-0007",
		.codec_dai_name = "ad193x-hifi",
		.cpu_dai_name = "I2S4",
		.codec_prefix = "y",
		.dai_fmt = SND_SOC_DAIFMT_DSP_A |
			SND_SOC_DAIFMT_NB_NF |
			SND_SOC_DAIFMT_CBM_CFM,
		.params.formats = SNDRV_PCM_FMTBIT_S32_LE,
		.params.rate_min = 48000,
		.params.rate_max = 48000,
		.params.channels_min = 8,
		.params.channels_max = 8,
	},
	.dai_config[2] = {
		.cpu_name = "tegra30-spdif",
		.codec_name = "spdif-dit.0",
		.codec_dai_name = "dit-hifi",
		.cpu_dai_name = "SPDIF",
		.codec_prefix = "z",
		.params.formats = SNDRV_PCM_FMTBIT_S16_LE,
		.params.rate_min = 48000,
		.params.rate_max = 48000,
		.params.channels_min = 2,
		.params.channels_max = 2,
	},
	.dev_num = 3,
	/* initialize AMX config */
	.amx_config[0] = {
		.slot_map = tegra_vcm30t124_amx_slot_map,
		.params = tegra_vcm30t124_amx_input_params,
	},
	.amx_config[1] = {
		.slot_map = tegra_vcm30t124_amx_slot_map,
		.params = tegra_vcm30t124_amx_input_params,
	},
	.num_amx = 2,
	/* initialize ADX config */
	.adx_config[0] = {
		.slot_map = tegra_vcm30t124_adx_slot_map,
		.params = tegra_vcm30t124_adx_input_params,
	},
	.adx_config[1] = {
		.slot_map = tegra_vcm30t124_adx_slot_map,
		.params = tegra_vcm30t124_adx_input_params,
	},
	.num_adx = 2,
	/* initialize DAPM routes */
	.dapm_routes = tegra_e1860_b00_audio_map,
	.num_dapm_routes = ARRAY_SIZE(tegra_e1860_b00_audio_map),
	/* sound card: tegra-ak4618-ad1937 */
	.card_name = "tegra-ak-ad",
};

/* voice call related structures
 * I2S0<-DAM0<-I2S4 (DAM0 in_rate = 16khz)
 * I2S0->DAM1->I2S4 (DAM1 in_rate = 48khz) */
static unsigned int tegra_voice_call_in_srate[2] = {
	16000, /* DAM0 in_srate */
	48000, /* DAM1 in_srate */
};

static struct tegra_vcm30t124_platform_data tegra_voice_call_pdata = {
	/* initialize DAI link config */
	.dai_config[0] = {
		.cpu_name = "tegra30-i2s.0",
		.codec_name = "ak4618.0-0010",
		.codec_dai_name = "ak4618-hifi",
		.cpu_dai_name = "I2S0",
		.codec_prefix = "x",
		.dai_fmt = SND_SOC_DAIFMT_DSP_A |
			SND_SOC_DAIFMT_NB_NF |
			SND_SOC_DAIFMT_CBS_CFS,
		.params.formats = SNDRV_PCM_FMTBIT_S32_LE,
		.params.rate_min = 48000,
		.params.rate_max = 48000,
		.params.channels_min = 8,
		.params.channels_max = 8,
	},
	.dai_config[1] = {
		.cpu_name = "tegra30-i2s.4",
		.codec_name = "spdif-dit.0",
		.codec_dai_name = "dit-hifi",
		.cpu_dai_name = "I2S4",
		.codec_prefix = "y",
		.dai_fmt = SND_SOC_DAIFMT_I2S |
			SND_SOC_DAIFMT_NB_NF |
			SND_SOC_DAIFMT_CBS_CFS,
		.params.formats = SNDRV_PCM_FMTBIT_S16_LE,
		.params.rate_min = 16000,
		.params.rate_max = 16000,
		.params.channels_min = 2,
		.params.channels_max = 2,
	},
	.dev_num = 2,
	/* initialize DAPM routes */
	.dapm_routes = tegra_voice_call_audio_map,
	.num_dapm_routes = ARRAY_SIZE(tegra_voice_call_audio_map),
	/* initialize DAM input sampling rate */
	.dam_in_srate = tegra_voice_call_in_srate,
	.num_dam = 2,
	/* sound card: tegra-ak4618-voicecall */
	.card_name = "tegra-ak-vc",
};

static struct platform_device tegra_snd_vcm30t124 = {
	.name = "tegra-snd-vcm30t124",
	.id = 0,
};

static struct platform_device tegra_spdif_dit = {
	.name = "spdif-dit",
	.id = 0,
};

void __init vcm30_t124_audio_init(void)
{
	int is_e1860_b00 = tegra_is_board(NULL, "61860", NULL, "300", NULL);
	int modem_id = tegra_get_modem_id();
	int is_e1892 = 0;

	/* check the version of embedded breakout board */
	is_e1892 = tegra_is_board(NULL, "61892", NULL, NULL, NULL);

	/* set max9485 addr as priv data for a0x and b00 */
	tegra_e1860_a0x_pdata.priv_data =
	tegra_e1860_b00_pdata.priv_data =
	tegra_voice_call_pdata.priv_data =
		(void *)(is_e1892 ? 0x70 : 0x60);

	/* initialize the platform data structure */
	tegra_snd_vcm30t124.dev.platform_data = is_e1860_b00 ?
		(modem_id ? &tegra_voice_call_pdata :
			&tegra_e1860_b00_pdata) : &tegra_e1860_a0x_pdata;

	/* register the platform device and dummy codec if any */
	platform_device_register(&tegra_snd_vcm30t124);
	platform_device_register(&tegra_spdif_dit);
}