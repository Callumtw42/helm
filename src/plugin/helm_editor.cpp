/* Copyright 2013-2017 Matt Tytel
 *
 * helm is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * helm is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with helm.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "helm_editor.h"

#include "default_look_and_feel.h"
#include "helm_common.h"
#include "helm_plugin.h"
#include "load_save.h"

#define WIDTH 992
#define HEIGHT 734

HelmEditor::HelmEditor(HelmPlugin& helm) : AudioProcessorEditor(&helm), SynthGuiInterface(&helm),
                                           helm_(helm) {
  setLookAndFeel(DefaultLookAndFeel::instance());

  addAndMakeVisible(gui_);
  gui_->setOutputMemory(helm.getOutputMemory());
  gui_->animate(LoadSave::shouldAnimateWidgets());
  setSize(WIDTH, HEIGHT);
  setResizable(true, true);

  repaint();
}

void HelmEditor::paint(Graphics& g) {
  g.fillAll(Colours::white);
}

void HelmEditor::resized() {
  gui_->setBounds(getLocalBounds());
}

void HelmEditor::updateFullGui() {
  SynthGuiInterface::updateFullGui();
  helm_.updateHostDisplay();
}
